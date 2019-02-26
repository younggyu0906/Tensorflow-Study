package koreatech.cse.controller;


import koreatech.cse.domain.Board;
import koreatech.cse.domain.Searchable;
import koreatech.cse.repository.BoardMapper;
import koreatech.cse.service.BoardService;
import org.springframework.stereotype.Controller;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.validation.FieldError;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;

import javax.inject.Inject;
import java.util.List;

@Controller
@RequestMapping("/board")
public class BoardController {

    @Inject
    private BoardMapper boardMapper;
    @Inject
    private BoardService boardService;

    @RequestMapping("/write")
    public String write(Model model) {
        Board board = new Board();
        model.addAttribute("board", board);
        return "write";
    }

    @Transactional
    @RequestMapping(value="/write", method= RequestMethod.POST)
    public String write(@ModelAttribute Board board, BindingResult result) {
        if (result.hasErrors()) {
            List<FieldError> errors = result.getFieldErrors();
            for (FieldError error : errors ) {
                System.out.println (error.getObjectName() + " - " + error.getDefaultMessage());
            }
        }
        //DB에 board 작성
        boardService.write(board);
        System.out.println("board = " + board);
        return "redirect:/board/board";

    }

    @RequestMapping(value = "/board", method = RequestMethod.GET)
    public String boardList(Model model, @RequestParam(required=false) String subject, @RequestParam(required=false) String order) {
        Searchable searchable = new Searchable();
        searchable.setSubject(subject);
        searchable.setOrderParam(order);
        model.addAttribute("boards", boardMapper.findByScript(searchable));
        return "/board";
    }


    //DB에서 해당하는 id를 찾은 후 조회수를 1 증가시킨 다음 그 것을 보여준다.
    @RequestMapping(value = "/article", method = RequestMethod.GET)
    public String article(Model model, @RequestParam(required=false) int id) {
        Board board = boardMapper.findOne(id);
        boardMapper.increseOneHits(board);
        model.addAttribute("board",boardMapper.findOne(id));
        return "article";
    }
}
