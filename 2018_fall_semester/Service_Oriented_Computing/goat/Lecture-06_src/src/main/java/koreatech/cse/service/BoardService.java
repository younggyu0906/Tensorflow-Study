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

    public Boolean write(Board board) {
        if(board.getSubject() == null || board.getContents() ==  null)
            return false;

        //insert하기 전에 regdate에 현재 DATE를 넣어준다.
        Date date = new Date();
        board.setRegdate(date);
        boardMapper.insert(board);

        System.out.println("board created: " + date);
        return true;
    }

}
