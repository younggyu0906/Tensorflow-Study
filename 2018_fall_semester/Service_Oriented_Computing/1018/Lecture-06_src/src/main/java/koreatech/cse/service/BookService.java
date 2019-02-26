package koreatech.cse.service;

import koreatech.cse.domain.Book;
import koreatech.cse.repository.BookMapper;
import org.springframework.stereotype.Service;

import javax.inject.Inject;
import java.util.Date;

@Service
public class BookService {
    @Inject
    private BookMapper bookMapper;

    public Boolean signup(Book book) {
        if(book.getBookName() == null || book.getIssn() ==  null)
            return false;

        bookMapper.insert(book);

        System.out.println("Book created: " + new Date());
        return true;
    }
}
