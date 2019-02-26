package koreatech.cse.repository;


import koreatech.cse.domain.Searchable;
import koreatech.cse.domain.Book;
import koreatech.cse.repository.provider.UserSqlProvider;
import org.apache.ibatis.annotations.*;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface BookMapper {
    @Insert("INSERT INTO BOOKS (BOOKNAME, ISSN) VALUES (#{bookName}, #{issn})")
    @SelectKey(statement = "SELECT LAST_INSERT_ID()", keyProperty = "id", before = false, resultType = int.class)
    void insert(Book book);

    @Update("UPDATE BOOKS SET BOOKNAME = #{bookName}, ISSN = #{issn} WHERE ID = #{id}")
    void update(Book book);

    @Select("SELECT * FROM BOOKS WHERE ID = #{id}")
    Book findOne(@Param("id") int id);

    @Delete("DELETE FROM BOOKS WHERE ID = #{id}")
    void delete(@Param("id") int id);

    @SelectProvider(type = UserSqlProvider.class, method = "findAllByProvider")
    List<Book> findByProvider(Searchable searchable);

    //@formatter off
    @Select("<script>"
            + "SELECT * FROM BOOKS"
            + "<if test='bookName != null'> WHERE BOOKNAME = #{bookName}</if>"
            + "<if test='issn != null'> WHERE ISSN = #{issn}</if>"
//            + "<if test='name != null and email != null'> OR EMAIL = #{email}</if>"
//            + "<if test='orderParam != null'>ORDER BY ${orderParam} DESC</if>"
            + "</script>")
    //@formatter on
    List<Book> findByScript(Searchable searchable);

}
