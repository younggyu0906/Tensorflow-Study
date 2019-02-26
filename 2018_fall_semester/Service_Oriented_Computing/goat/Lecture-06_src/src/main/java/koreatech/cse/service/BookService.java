package koreatech.cse.service;

import koreatech.cse.domain.Book;
import koreatech.cse.domain.User;
import koreatech.cse.repository.BookMapper;
import koreatech.cse.repository.UserMapper;
import org.springframework.stereotype.Service;

import javax.inject.Inject;
import java.util.Date;

@Service
public class BookService {
    @Inject
    private BookMapper bookMapper;

    public Boolean signup(Book book) {
        if(book.getName() == null || book.getIssn() ==  null)
            return false;

        bookMapper.insert(book);

        System.out.println("Book created: " + new Date());
        return true;
    }
}
