package koreatech.cse.repository;


import koreatech.cse.domain.BoardSearchable;
import koreatech.cse.domain.Searchable;
import koreatech.cse.domain.Board;
import koreatech.cse.repository.provider.UserSqlProvider;
import org.apache.ibatis.annotations.*;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface BoardMapper {
    @Insert("INSERT INTO BOARD (SUBJECT, CONTENTS, REGDATE, HITS) VALUES (#{subject}, #{contents}, now(), #{hits})")
    @SelectKey(statement = "SELECT LAST_INSERT_ID()", keyProperty = "id", before = false, resultType = int.class)
    void insert(Board board);

    @Update("UPDATE USERS SET SUBJECT = #{subject}, CONTENTS = #{contents}, REGDATE = now(), HITS = #{hits} WHERE ID = #{id}")
    void update(Board board);

    @Select("SELECT * FROM BOARD WHERE ID = #{id}")
    Board findOne(@Param("id") int id);

    @Delete("DELETE FROM BOARD WHERE ID = #{id}")
    void delete(@Param("id") int id);

    @SelectProvider(type = UserSqlProvider.class, method = "findAllByProvider")
    List<Board> findByProvider(BoardSearchable searchable);

    //@formatter off
    @Select("<script>"
            + "SELECT * FROM BOARD"
            + "<if test='subject != null'> WHERE SUBJECT = #{subject}</if>"
            + "<if test='contents != null'> WHERE CONTENTS = #{contents}</if>"
            + "<if test='orderParam != null'>ORDER BY ${orderParam} DESC</if>"
            + "</script>")
    //@formatter on
    List<Board> findByScript(BoardSearchable searchable);

}
