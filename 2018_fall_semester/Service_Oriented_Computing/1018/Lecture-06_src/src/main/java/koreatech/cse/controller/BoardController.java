package koreatech.cse.controller;

import koreatech.cse.domain.Board;
import koreatech.cse.domain.BoardSearchable;
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
import java.util.Date;
import java.util.List;

// board, article, write

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
//    @ResponseBody
    public String write(@ModelAttribute Board board, BindingResult result) {
        if (result.hasErrors()) {
            List<FieldError> errors = result.getFieldErrors();
            for (FieldError error : errors ) {
                System.out.println (error.getObjectName() + " - " + error.getDefaultMessage());
            }
        }
        board.setHits(0);
        boardMapper.insert(board);
        System.out.println (board.getId());
        //double i = 3 / 0;
        //System.out.println("i = " + i);
        System.out.println("board = " + board);
        return "redirect:/board/board";
    }
//    public String signup(@ModelAttribute User user) {
//        userService.signup(user);
//        return "success";
//    }

//    @RequestMapping("/edit")
//    public String edit(Model model, @RequestParam int id) {
//        User user = userMapper.findOne(id);
//        model.addAttribute("user", user);
//        return "edit";
//    }
//
//    @RequestMapping(value="/edit", method= RequestMethod.POST)
//    public String edit(@ModelAttribute User user) {
//        userMapper.update(user);
//        return "redirect:/user/list";
//
//    }
//
//    @RequestMapping(value="/delete", method= RequestMethod.GET)
//    public String delete(@RequestParam int id) {
//        userMapper.delete(id);
//        return "redirect:/user/list";
//
//    }

    @RequestMapping(value = "/board", method = RequestMethod.GET)
    public String list(Model model, @RequestParam(required=false) String subject, @RequestParam(required=false) String contents, Date regdate, int hits, @RequestParam(required=false) String order) {
        BoardSearchable searchable = new BoardSearchable();

        searchable.setSubject(subject);
        searchable.setContents(contents);
        searchable.setRegdate(regdate);
//        searchable.setHits(hits);
        searchable.setOrderParam(order);
        //model.addAttribute("users", userMapper.findByProvider(searchable));
        model.addAttribute("boards", boardMapper.findByScript(searchable));
        return "board";
    }

}
