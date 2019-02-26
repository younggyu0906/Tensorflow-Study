package koreatech.cse.repository;


import koreatech.cse.domain.Book;
import koreatech.cse.domain.Searchable;
import koreatech.cse.repository.provider.BookSqlProvider;
import koreatech.cse.repository.provider.UserSqlProvider;
import org.apache.ibatis.annotations.*;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface BookMapper {
    @Insert("INSERT INTO BOOKS (NAME, ISSN) VALUES (#{name}, #{issn})")
    //가장 마지막에 성공된 것의 column번호를 반환하기 때문이다.
    @SelectKey(statement = "SELECT LAST_INSERT_ID()", keyProperty = "id", before = false, resultType = int.class)
    void insert(Book book);

    @Update("UPDATE BOOKS SET NAME = #{name}, ISSN = #{issn} WHERE ID = #{id}")
    void update(Book book);

    @Select("SELECT * FROM BOOKS WHERE ID = #{id}")
    Book findOne(@Param("id") int id);

    @Delete("DELETE FROM BOOKS WHERE ID = #{id}")
    void delete(@Param("id") int id);

    @SelectProvider(type = BookSqlProvider.class, method = "findAllByProvider")
    List<Book> findByProvider(Searchable searchable);

    //@formatter off
    @Select("<script>"
            + "SELECT * FROM BOOKS"
            + "<if test='name != null'> WHERE NAME = #{name}</if>"
            + "<if test='name != null and issn != null'> OR issn = #{issn}</if>"
            + "<if test='orderParam != null'>ORDER BY ${orderParam} DESC</if>"
            + "</script>")
    //@formatter on
    List<Book> findByScript(Searchable searchable);

}
