package koreatech.cse.repository.provider;

import koreatech.cse.domain.Searchable;
import org.apache.ibatis.jdbc.SQL;

public class BoardSqlProvider {

    public String findAllByProvider(final Searchable searchable) {
        return new SQL() {
            {
                SELECT("*");
                FROM("BOARD");
                if(searchable.getSubject() != null) {
                    WHERE("SUBJECT = #{SUBJECT}");
                }
                if(searchable.getOrderParam() != null) {

                    ORDER_BY(searchable.getOrderParam() + " DESC");
                }
            }
        }.toString();
    }

}
