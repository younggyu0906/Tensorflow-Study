package koreatech.cse.controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
@RequestMapping("/")
public class HomeController {

//    @RequestMapping("")
//    public String home(Model model) {
//        model.addAttribute("textFromController", "Wo");
//        return "hello";
//    }
//
//    @RequestMapping("/a")
//    public String home2(Model model) {
//        model.addAttribute("textFromController", "World!");
//        return "hello";
//    }
    @RequestMapping("")
    public String home(Model model) {
        model.addAttribute("textFromController_num", "2013136021");
        model.addAttribute("textFromController_name", "김영규");
        return "student_number";
    }
}
