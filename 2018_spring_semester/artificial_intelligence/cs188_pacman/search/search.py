# search.py
# ---------
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


"""
In search.py, you will implement generic search algorithms which are called by
Pacman agents (in searchAgents.py).
"""

import util

class SearchProblem:
    """
    This class outlines the structure of a search problem, but doesn't implement
    any of the methods (in object-oriented terminology: an abstract class).

    You do not need to change anything in this class, ever.
    """

    def getStartState(self):
        """
        Returns the start state for the search problem.
        """
        util.raiseNotDefined()

    def isGoalState(self, state):
        """
          state: Search state

        Returns True if and only if the state is a valid goal state.
        """
        util.raiseNotDefined()

    def getSuccessors(self, state):
        """
          state: Search state

        For a given state, this should return a list of triples, (successor,
        action, stepCost), where 'successor' is a successor to the current
        state, 'action' is the action required to get there, and 'stepCost' is
        the incremental cost of expanding to that successor.
        """
        util.raiseNotDefined()

    def getCostOfActions(self, actions):
        """
         actions: A list of actions to take

        This method returns the total cost of a particular sequence of actions.
        The sequence must be composed of legal moves.
        """
        util.raiseNotDefined()


def tinyMazeSearch(problem):
    """
    Returns a sequence of moves that solves tinyMaze.  For any other maze, the
    sequence of moves will be incorrect, so only use this for tinyMaze.
    """
    from game import Directions
    s = Directions.SOUTH
    w = Directions.WEST
    return  [s, s, w, s, w, w, s, w]

class Path:
    def __init__(self, l, d, c):
        self.location = l
        self.direction = d
        self.cost = c


def depthFirstSearch(problem):
    """
    Search the deepest nodes in the search tree first.

    Your search algorithm needs to return a list of actions that reaches the
    goal. Make sure to implement a graph search algorithm.

    To get started, you might want to try some of these simple commands to
    understand the search problem that is being passed in:

    print "Start:", problem.getStartState()
    print "Is the start a goal?", problem.isGoalState(problem.getStartState())
    print "Start's successors:", problem.getSuccessors(problem.getStartState())
    """
    "*** YOUR CODE HERE ***"
    print "***************depthFirstSearch***************"
    path = Path([problem.getStartState()], [], 0)       # declare a path object
    fringe = util.Stack()                               # declare fringe as a Stack
    fringe.push(path)                                   # push a path object into fringe.
    visited = list();
    while not fringe.isEmpty():                         # loop until fringe is empty
        current_step = fringe.pop()                     # pop
        current_location = current_step.location[-1]    # current location(last item in list)

        if current_location not in visited:             # graph search
            visited.append(current_location)

        print "locations :", current_step.location
        if problem.isGoalState(current_location):       # if current location is Goal
            print "directions :", current_step.direction
            print "**********************************************"
            return current_step.direction               # return direction (from start to goal)
        else:
            next_steps = problem.getSuccessors(current_location)    # next step
            for next_step in next_steps:                # for loop by next_steps size
                next_location = next_step[0]            # next location
                next_direction = next_step[1]           # next direction
                next_cost = next_step[2]                # next cost
                if next_location not in visited:#current_step.location:      # if next_location is not in location list
                    next_locations = list(current_step.location)    # type cast to list
                    next_locations.append(next_location)            # append next location
                    next_directions = list(current_step.direction)  # type cast to list
                    next_directions.append(next_direction)          # append next direction
                    next_costs = current_step.cost + next_cost      # next costs is current_cost + next_cost
                    next_path = Path(next_locations, next_directions, next_costs)   # declare next_path as a Path object
                    fringe.push(next_path)                          # push next_path object into fringe.
    return []
    util.raiseNotDefined()

def breadthFirstSearch(problem):
    """Search the shallowest nodes in the search tree first."""
    "*** YOUR CODE HERE ***"
    print "***************breadthFirstSearch***************"
    path = Path([problem.getStartState()], [], 0)       # declare a path object
    fringe = util.Queue()                               # declare fringe as a Queue
    fringe.push(path)                                   # push a path object into fringe
    visited = list();
    while not fringe.isEmpty():                         # loop until fringe is empty
        current_step = fringe.pop()                     # pop
        current_location = current_step.location[-1]    # current location(last item in list)

        if current_location not in visited:  # graph search
            visited.append(current_location)

        # print "locations :", current_step.location
        if problem.isGoalState(current_location):       # if current location is Goal
            print "directions :", current_step.direction
            print "**********************************************"
            return current_step.direction               # return direction (from start to goal)
        else:
            next_steps = problem.getSuccessors(current_location)    # next step
            for next_step in next_steps:                # for loop by next_steps size
                next_location = next_step[0]            # next location
                next_direction = next_step[1]           # next direction
                next_cost = next_step[2]                # next cost
                if next_location not in visited:#current_step.location:      # if next_location is not in location list
                    next_locations = list(current_step.location)    # type cast to list
                    next_locations.append(next_location)            # append next location
                    next_directions = list(current_step.direction)  # type cast to list
                    next_directions.append(next_direction)          # append next direction
                    next_costs = current_step.cost + next_cost      # next costs is current_cost + next_cost
                    next_path = Path(next_locations, next_directions, next_costs)   # declare next_path as a Path object
                    fringe.push(next_path)                          # push next_path object into fringe.
    return []
    util.raiseNotDefined()

def uniformCostSearch(problem):
    """Search the node of least total cost first."""
    "*** YOUR CODE HERE ***"
    print "***************uniformCostSearch***************"
    path = Path([problem.getStartState()], [], 0)       # declare a path object
    fringe = util.PriorityQueue()                       # declare fringe as a Queue
    fringe.push(path, path.cost)                        # push a path object into fringe
    visited = list();
    while not fringe.isEmpty():                         # loop until fringe is empty
        current_step = fringe.pop()                     # pop the item with the smallest cost
        current_location = current_step.location[-1]    # current location(last item in list)

        if current_location not in visited:  # graph search
            visited.append(current_location)

        print "locations :", current_step.location
        if problem.isGoalState(current_location):       # if current location is Goal
            print "directions :", current_step.direction
            print "**********************************************"
            return current_step.direction               # return direction (from start to goal)
        else:
            next_steps = problem.getSuccessors(current_location)   # next step
            for next_step in next_steps:                # for loop by next_steps size
                next_location = next_step[0]            # next location
                next_direction = next_step[1]           # next direction
                next_cost = next_step[2]                # next cost
                if next_location not in visited:#current_step.location:      # if next_location is not in location list
                    next_locations = list(current_step.location)    # type cast to list
                    next_locations.append(next_location)            # append next location
                    next_directions = list(current_step.direction)  # type cast to list
                    next_directions.append(next_direction)          # append next direction
                    next_costs = current_step.cost + next_cost      # next costs is current_cost + next_cost
                    next_path = Path(next_locations, next_directions, next_costs)  # declare next_path as a Path object
                    fringe.push(next_path, next_path.cost)          # push next_path object into fringe.
    return []

    util.raiseNotDefined()

def nullHeuristic(state, problem=None):
    """
    A heuristic function estimates the cost from the current state to the nearest
    goal in the provided SearchProblem.  This heuristic is trivial.
    """
    return 0

def aStarSearch(problem, heuristic=nullHeuristic):
    """Search the node that has the lowest combined cost and heuristic first."""
    "*** YOUR CODE HERE ***"
    print "***************aStarSearch***************"
    path = Path([problem.getStartState()], [], 0)       # declare a path object
    fringe = util.PriorityQueue()                       # declare fringe as a Queue
    fringe.push(path, path.cost)                        # push a path object into fringe
    visited = list();
    while not fringe.isEmpty():                         # loop until fringe is empty
        current_step = fringe.pop()                     # pop the item with the smallest cost
        current_location = current_step.location[-1]    # current location(last item in list)

        if current_location not in visited:  # graph search
            visited.append(current_location)

        #print "locations :", current_step.location
        if problem.isGoalState(current_location):       # if current location is Goal
            print "directions :", current_step.direction
            print "**********************************************"
            return current_step.direction               # return direction (from start to goal)
        else:
            next_steps = problem.getSuccessors(current_location)   # next step
            for next_step in next_steps:                # for loop by next_steps size
                next_location = next_step[0]            # next location
                next_direction = next_step[1]           # next direction
                next_cost = next_step[2]                # next cost
                if next_location not in visited:#current_step.location:      # if next_location is not in location list
                    next_locations = list(current_step.location)    # type cast to list
                    next_locations.append(next_location)            # append next location
                    next_directions = list(current_step.direction)  # type cast to list
                    next_directions.append(next_direction)          # append next direction
                    heuristic_value = heuristic(current_location, problem)  # heuristic
                    act_costs = current_step.cost + next_cost
                    next_costs = act_costs + heuristic_value   # next costs is current_cost + next_cost + heuristic_value
                    next_path = Path(next_locations, next_directions, act_costs)  # declare next_path as a Path object
                    fringe.push(next_path, next_costs)          # push next_path object into fringe.
    return []

    util.raiseNotDefined()


# Abbreviations
bfs = breadthFirstSearch
dfs = depthFirstSearch
astar = aStarSearch
ucs = uniformCostSearch
