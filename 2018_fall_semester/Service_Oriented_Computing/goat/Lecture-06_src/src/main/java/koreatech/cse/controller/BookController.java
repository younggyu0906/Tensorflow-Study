package koreatech.cse.controller;

import koreatech.cse.domain.Book;
import koreatech.cse.domain.Searchable;
import koreatech.cse.repository.BookMapper;
import koreatech.cse.service.BookService;
import org.springframework.stereotype.Controller;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.validation.FieldError;
import org.springframework.web.bind.annotation.*;

import javax.inject.Inject;
import java.util.List;

@Controller

@RequestMapping("/book")
public class BookController {
    @Inject
    private BookMapper bookMapper;
    @Inject
    private BookService bookService;


    @RequestMapping("/signup")
    public String signup(Model model) {
        Book book = new Book();
        model.addAttribute("book", book);
        return "bookSignup";
    }

    @Transactional
    @RequestMapping(value="/signup", method= RequestMethod.POST)
    public String signup(@ModelAttribute Book book, BindingResult result) {
        if (result.hasErrors()) {
            List<FieldError> errors = result.getFieldErrors();
            for (FieldError error : errors ) {
                System.out.println (error.getObjectName() + " - " + error.getDefaultMessage());
            }
        }

        bookMapper.insert(book);    //insert를 통해 DB에 업로드.
        System.out.println(book.getId());   //insert에서 만들어준 Id를 print로 찍어주기
        //double i = 3 / 0;
        //System.out.println("i = " + i);
        System.out.println("book = " + book);
        return "redirect:/book/booklist";   //redirect의 기능 => 다시 컨트롤러의 user부터 찾아서 다시 시작된다. 바로 list로 가는 것이 아님.

    }


    @RequestMapping(value = "/list", method = RequestMethod.GET)
    public String list(Model model, @RequestParam(required=false) String name, @RequestParam(required=false) String issn, @RequestParam(required=false) String order) {
        Searchable searchable = new Searchable();
        searchable.setName(name);
        searchable.setIssn(issn);
        model.addAttribute("books", bookMapper.findByProvider(searchable));
        //model.addAttribute("users", userMapper.findByScript(searchable));
        return "list";
    }

    @RequestMapping("/edit")
    public String edit(Model model, @RequestParam int id) {
        Book book = bookMapper.findOne(id);
        model.addAttribute("book", book);
        return "edit";
    }

    @RequestMapping(value="/edit", method= RequestMethod.POST)
    public String edit(@ModelAttribute Book book) {
        bookMapper.update(book);
        return "redirect:/book/list";

    }

    @RequestMapping(value="/delete", method= RequestMethod.GET)
    public String delete(@RequestParam int id) {
        bookMapper.delete(id);
        return "redirect:/book/list";

    }
}
