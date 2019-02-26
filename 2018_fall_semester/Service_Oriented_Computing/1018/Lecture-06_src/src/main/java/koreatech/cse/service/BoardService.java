package koreatech.cse.service;

import koreatech.cse.domain.Board;
import koreatech.cse.repository.BoardMapper;
import org.springframework.stereotype.Service;

import javax.inject.Inject;
import java.util.Date;

@Service
public class BoardService {
    @Inject
    private BoardMapper boardMapper;

    public Boolean signup(Board board) {
        if(board.getSubject() == null || board.getContents() ==  null)
            return false;

        boardMapper.insert(board);

        System.out.println("Board created: " + new Date());
        return true;
    }
}
