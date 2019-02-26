package koreatech.cse.controller;

import koreatech.cse.domain.Book;
import koreatech.cse.domain.Searchable;
import koreatech.cse.domain.User;
import koreatech.cse.repository.BookMapper;
import koreatech.cse.repository.UserMapper;
import koreatech.cse.service.BookService;
import koreatech.cse.service.UserService;
import org.springframework.stereotype.Controller;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.validation.FieldError;
import org.springframework.web.bind.annotation.*;

import javax.inject.Inject;
import java.util.List;

@Controller

@RequestMapping("/user")
public class UserController {
    @Inject
    private UserMapper userMapper;
    @Inject
    private UserService userService;
    @Inject
    private BookMapper bookMapper;
    @Inject
    private BookService bookService;

    @RequestMapping("/signup")
    public String signup(Model model) {
        User user = new User();
        model.addAttribute("user", user);
        return "signup";
    }

    @Transactional
    @RequestMapping(value="/signup", method= RequestMethod.POST)
//    @ResponseBody
    public String signup(@ModelAttribute User user, BindingResult result) {
        if (result.hasErrors()) {
            List<FieldError> errors = result.getFieldErrors();
            for (FieldError error : errors ) {
                System.out.println (error.getObjectName() + " - " + error.getDefaultMessage());
            }
        }
        Book book = new Book();
        book.setBookName(user.getBook().getBookName());
//        issn
        bookMapper.insert(book);

        userMapper.insert(user);
        System.out.println (user.getId());
        //double i = 3 / 0;
        //System.out.println("i = " + i);
        System.out.println("user = " + user);
        return "redirect:/user/list";

    }
//    public String signup(@ModelAttribute User user) {
//        userService.signup(user);
//        return "success";
//    }

    @RequestMapping("/edit")
    public String edit(Model model, @RequestParam int id) {
        User user = userMapper.findOne(id);
        model.addAttribute("user", user);
        return "edit";
    }

    @RequestMapping(value="/edit", method= RequestMethod.POST)
    public String edit(@ModelAttribute User user) {
        userMapper.update(user);
        return "redirect:/user/list";

    }

    @RequestMapping(value="/delete", method= RequestMethod.GET)
    public String delete(@RequestParam int id) {
        userMapper.delete(id);
        return "redirect:/user/list";

    }

    @RequestMapping(value = "/list", method = RequestMethod.GET)
    public String list(Model model, @RequestParam(required=false) String name, @RequestParam(required=false) String email, @RequestParam(required=false) String order) {
        Searchable searchable = new Searchable();
        searchable.setName(name);
        searchable.setEmail(email);
        searchable.setOrderParam(order);
        //model.addAttribute("users", userMapper.findByProvider(searchable));
        model.addAttribute("users", userMapper.findByScript(searchable));
        return "list";
    }



}
