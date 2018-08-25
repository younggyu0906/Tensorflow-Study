# multiAgents.py
# --------------
# Licensing Information:  You are free to use or extend these projects for
# educational purposes provided that (1) you do not distribute or publish
# solutions, (2) you retain this notice, and (3) you provide clear
# attribution to UC Berkeley, including a link to http://ai.berkeley.edu.
# 
# Attribution Information: The Pacman AI projects were developed at UC Berkeley.
# The core projects and autograders were primarily created by John DeNero
# (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# Student side autograding was added by Brad Miller, Nick Hay, and
# Pieter Abbeel (pabbeel@cs.berkeley.edu).


from util import manhattanDistance
from game import Directions
import random, util

from game import Agent

class ReflexAgent(Agent):
    """
      A reflex agent chooses an action at each choice point by examining
      its alternatives via a state evaluation function.

      The code below is provided as a guide.  You are welcome to change
      it in any way you see fit, so long as you don't touch our method
      headers.
    """


    def getAction(self, gameState):
        """
        You do not need to change this method, but you're welcome to.

        getAction chooses among the best options according to the evaluation function.

        Just like in the previous project, getAction takes a GameState and returns
        some Directions.X for some X in the set {North, South, West, East, Stop}
        """
        # Collect legal moves and successor states
        legalMoves = gameState.getLegalActions()

        # Choose one of the best actions
        scores = [self.evaluationFunction(gameState, action) for action in legalMoves]
        bestScore = max(scores)
        bestIndices = [index for index in range(len(scores)) if scores[index] == bestScore]
        chosenIndex = random.choice(bestIndices) # Pick randomly among the best

        "Add more of your code here if you want to"

        return legalMoves[chosenIndex]

    def evaluationFunction(self, currentGameState, action):
        """
        Design a better evaluation function here.

        The evaluation function takes in the current and proposed successor
        GameStates (pacman.py) and returns a number, where higher numbers are better.

        The code below extracts some useful information from the state, like the
        remaining food (newFood) and Pacman position after moving (newPos).
        newScaredTimes holds the number of moves that each ghost will remain
        scared because of Pacman having eaten a power pellet.

        Print out these variables to see what you're getting, then combine them
        to create a masterful evaluation function.
        """
        # Useful information you can extract from a GameState (pacman.py)
        successorGameState = currentGameState.generatePacmanSuccessor(action)
        newPos = successorGameState.getPacmanPosition()
        newFood = successorGameState.getFood()
        newGhostStates = successorGameState.getGhostStates()
        newScaredTimes = [ghostState.scaredTimer for ghostState in newGhostStates]

        "*** YOUR CODE HERE ***"
        newGhostPos = successorGameState.getGhostPositions()        # ghost positions

        foodScore = 0
        if len(newFood.asList()) == 0:      # if no food, food score is 1
            foodScore = 1
        else:                               # else, food score is 1/closest distance
            for foodPos in newFood.asList():
                maxScore = float("inf")
                foodScore = 1 / float(min([maxScore] + [util.manhattanDistance(newPos, foodPos)])) # closest food
        ghostScore = 0
        # The longer the distance between Pacman and the ghost, the bigger the score.
        closestGhost = min([util.manhattanDistance(newPos, ghostPos) for ghostPos in newGhostPos]) # closest ghost
        if closestGhost < 2:    # too close
            ghostScore = -10000000
        return (successorGameState.getScore() - currentGameState.getScore()) + foodScore + ghostScore
        # return successorGameState.getScore()

def scoreEvaluationFunction(currentGameState):
    """
      This default evaluation function just returns the score of the state.
      The score is the same one displayed in the Pacman GUI.

      This evaluation function is meant for use with adversarial search agents
      (not reflex agents).
    """
    return currentGameState.getScore()

class MultiAgentSearchAgent(Agent):
    """
      This class provides some common elements to all of your
      multi-agent searchers.  Any methods defined here will be available
      to the MinimaxPacmanAgent, AlphaBetaPacmanAgent & ExpectimaxPacmanAgent.

      You *do not* need to make any changes here, but you can if you want to
      add functionality to all your adversarial search agents.  Please do not
      remove anything, however.

      Note: this is an abstract class: one that should not be instantiated.  It's
      only partially specified, and designed to be extended.  Agent (game.py)
      is another abstract class.
    """

    def __init__(self, evalFn = 'scoreEvaluationFunction', depth = '2'):
        self.index = 0 # Pacman is always agent index 0
        self.evaluationFunction = util.lookup(evalFn, globals())
        self.depth = int(depth)

class MinimaxAgent(MultiAgentSearchAgent):
    """
      Your minimax agent (question 2)
    """

    def getAction(self, gameState):
        """
          Returns the minimax action from the current gameState using self.depth
          and self.evaluationFunction.

          Here are some method calls that might be useful when implementing minimax.

          gameState.getLegalActions(agentIndex):
            Returns a list of legal actions for an agent
            agentIndex=0 means Pacman, ghosts are >= 1

          gameState.generateSuccessor(agentIndex, action):
            Returns the successor game state after an agent takes an action

          gameState.getNumAgents():
            Returns the total number of agents in the game
        """
        "*** YOUR CODE HERE ***"
        # if state is terminal, return true, else, return false.
        def isTerminal(state, depth):
            return True if depth < 0 or state.isLose() or state.isWin() else False

        # max-value. return max value
        def maxValue(state, depth, agentId):
            depth -= 1      # depth - 1

            if isTerminal(state, depth):        # if state is terminal, call evaluation Fuc.
                return (self.evaluationFunction(state), None)

            value = float("-inf")
            for action in state.getLegalActions(agentId):   # loop legal actions
                next_state = state.generateSuccessor(agentId, action)   # next state
                minVal = minValue(next_state, depth, agentId + 1)[0]    # min value
                if minVal > value:          # if value < min value
                    value = minVal          # value <- min value
                    maxAction = action      # max action <- action
            return (value, maxAction)

        # min-value. return min value
        def minValue(state, depth, agentId):
            if isTerminal(state, depth):
                return (self.evaluationFunction(state), None)

            value = float("inf")
            # number of agent is pacman + ghosts.
            # last ghost call maxValue fuction.
            # if not last ghost, call minValue fuction.
            minOrMax, nextAgentId = (minValue, agentId + 1) if agentId < state.getNumAgents() - 1 else (maxValue, 0)
            for action in state.getLegalActions(agentId):   # loop legal actions
                next_state = state.generateSuccessor(agentId, action)   # next state
                maxVal = minOrMax(next_state, depth, nextAgentId)[0]    # max value
                if maxVal < value:          # if value > max value
                    value = maxVal          # value <- max value
                    minAction = action      # min action <- action
            return (value, minAction)

        return maxValue(gameState, self.depth, 0)[1]    # maxValue[0] = value, maxValue[1] = maxAction
        #util.raiseNotDefined()

class AlphaBetaAgent(MultiAgentSearchAgent):
    """
      Your minimax agent with alpha-beta pruning (question 3)
    """

    def getAction(self, gameState):
        """
          Returns the minimax action using self.depth and self.evaluationFunction
        """
        "*** YOUR CODE HERE ***"
        # same minimax
        def isTerminal(state, depth):
            return True if depth < 0 or state.isLose() or state.isWin() else False

        def maxValue(state, depth, agentId, alpha, beta):
            depth -= 1
            if isTerminal(state, depth):
                return (self.evaluationFunction(state), None)
            value = float("-inf")
            for action in state.getLegalActions(agentId):
                next_state = state.generateSuccessor(agentId, action)
                minVal = minValue(next_state, depth, agentId + 1, alpha, beta)[0]
                if minVal > value:
                    value = minVal
                    maxAction = action
                if value > beta:        # beta cut off
                    return (value, maxAction)
                alpha = max(alpha, value)
            return (value, maxAction)

        def minValue(state, depth, agentId, alpha, beta):
            if isTerminal(state, depth):
                return (self.evaluationFunction(state), None)
            value = float("inf")
            minOrMax, nextAgentId = (minValue, agentId + 1) if agentId < state.getNumAgents() - 1 else (maxValue, 0)
            for action in state.getLegalActions(agentId):
                next_state = state.generateSuccessor(agentId, action)
                maxVal = minOrMax(next_state, depth, nextAgentId, alpha, beta)[0]
                if maxVal < value:
                    value = maxVal
                    minAction = action
                if value < alpha:           # alpha cut off
                    return (value, minAction)
                beta = min(beta, value)
            return (value, minAction)

        return maxValue(gameState, self.depth, 0, float("-inf"), float("inf"))[1]
        util.raiseNotDefined()

class ExpectimaxAgent(MultiAgentSearchAgent):
    """
      Your expectimax agent (question 4)
    """

    def getAction(self, gameState):
        """
          Returns the expectimax action using self.depth and self.evaluationFunction

          All ghosts should be modeled as choosing uniformly at random from their
          legal moves.
        """
        "*** YOUR CODE HERE ***"
        def isTerminal(state, depth):
            return True if depth < 0 or state.isLose() or state.isWin() else False

        def maxValue(state, depth, agentId):
            depth -= 1
            if isTerminal(state, depth):
                return (self.evaluationFunction(state), None)
            value = float("-inf")
            for action in state.getLegalActions(agentId):
                next_state = state.generateSuccessor(agentId, action)
                minVal = expValue(next_state, depth, agentId + 1)[0]
                if minVal > value:
                    value = minVal
                    maxAction = action
            return (value, maxAction)

        def expValue(state, depth, agentId):
            if isTerminal(state, depth):
                return (self.evaluationFunction(state), None)
            value = 0
            expOrMax, nextAgentId = (expValue, agentId + 1) if agentId < state.getNumAgents() - 1 else (maxValue, 0)
            numLegalAction = len(state.getLegalActions(agentId))
            for action in state.getLegalActions(agentId):
                next_state = state.generateSuccessor(agentId, action)
                # value += value * probability
                value += expOrMax(next_state, depth, nextAgentId)[0] / float(numLegalAction)
                expAction = action
            return (value, expAction)

        return maxValue(gameState, self.depth, 0)[1]
        util.raiseNotDefined()

def betterEvaluationFunction(currentGameState):
    """
      Your extreme ghost-hunting, pellet-nabbing, food-gobbling, unstoppable
      evaluation function (question 5).

      DESCRIPTION: <write something here so we know what you did>
    """
    "*** YOUR CODE HERE ***"
    currentPos = currentGameState.getPacmanPosition()       # current agent's position
    currentFood = currentGameState.getFood()                # current foods
    currentGhost = currentGameState.getGhostPositions()     # current ghost's position
    currentCapsule = currentGameState.getCapsules()         # current capsule

    foodWeight = 1              # weight of food score
    capsuleWeight = 10          # weight of capsule score
    ghostWeight = 5             # weight of ghost score

    foodScore = 0               # food score
    capsuleScore = 0            # capsule score
    ghostScore = 0              # ghost score

    scaredTimes = [ghostState.scaredTimer for ghostState in currentGameState.getGhostStates()]  # scare times
    isScared = True if max(scaredTimes) != 0 else False     # if ghost is scare, isScare is True

    # Function that returns the minimum distance between agent and objects
    def closestDistance(currentPos, currentObjects):
        minDistance = float("inf")
        for objectPos in currentObjects:
            distance = util.manhattanDistance(currentPos, objectPos)
            if minDistance > distance:
                minDistance = distance
        return minDistance      # min distance

    closestFood = float(closestDistance(currentPos, currentFood))           # closest distance of food
    closestGhost = float(closestDistance(currentPos, currentGhost))         # closest distance of ghost
    closestCapsule = float(closestDistance(currentPos, currentCapsule))     # closest distance of capsule

    foodScore = 1 if len(currentFood.asList()) == 0 else 1 / closestFood    # foodScore = 1/closestFood. Without food, score = 1.
    capsuleScore = 2 if len(currentCapsule) == 0 else 1 / closestCapsule    # capsuleScore = 1/closestCapsle. Without capsule, score = 1

    if isScared:                                # if ghost is scared
        if closestGhost < max(scaredTimes):     # if closest ghost distance < scaredTime
            ghostWeight = 50                    # weight increase
            ghostScore = 100 if closestGhost < 1 else 1 / closestGhost      # if closestGhost < 1, ghostScore = 100, else, 1/closestGhost
        else:                                   # else, if closestGhost < 1, ghostScore = -100, else, 1/closestGhost
            ghostScore = -100 if closestGhost < 1 else 1 / closestGhost
    else:                                       # else, if closestGhost < 1, ghostScore = -100, else, 1/closestGhost
        ghostScore = -100 if closestGhost < 1 else 1 / closestGhost

    return (foodWeight * foodScore) + (ghostWeight * ghostScore) + (capsuleWeight * capsuleScore) + currentGameState.getScore()
    util.raiseNotDefined()

# Abbreviation
better = betterEvaluationFunction

