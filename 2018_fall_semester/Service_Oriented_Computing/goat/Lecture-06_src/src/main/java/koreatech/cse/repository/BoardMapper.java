package koreatech.cse.repository;

import koreatech.cse.domain.Board;
import koreatech.cse.domain.Searchable;
import koreatech.cse.repository.provider.BookSqlProvider;
import org.apache.ibatis.annotations.*;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface BoardMapper {

    @Insert("INSERT INTO BOARD (SUBJECT, CONTENTS, REGDATE) VALUES (#{subject}, #{contents}, #{regdate})")
    //가장 마지막에 성공된 것의 column번호를 반환하기 때문이다.
    @SelectKey(statement = "SELECT LAST_INSERT_ID()", keyProperty = "id", before = false, resultType = int.class)
    void insert(Board board);

    //hits +1증가시킨다.
    @Update("UPDATE BOARD SET HITS = #{hits}+1 WHERE ID = #{id}")
    void increseOneHits(Board board);

    @Select("SELECT * FROM BOARD WHERE ID = #{id}")
    Board findOne(@Param("id") int id);

    @Delete("DELETE FROM BOARD WHERE ID = #{id}")
    void delete(@Param("id") int id);

    @SelectProvider(type = BookSqlProvider.class, method = "findAllByProvider")
    List<Board> findByProvider(Searchable searchable);

    //@formatter off
    @Select("<script>"
            + "SELECT * FROM BOARD"
            + "<if test='subject != null'> WHERE SUBJECT = #{subject}</if>"
            + "<if test='orderParam != null'>ORDER BY ${orderParam} DESC</if>"
            + "</script>")
    //@formatter on
    List<Board> findByScript(Searchable searchable);

}
