package koreatech.cse.repository.provider;

import koreatech.cse.domain.Searchable;
import org.apache.ibatis.jdbc.SQL;

public class BookSqlProvider {

    public String findAllByProvider(final Searchable searchable) {
        return new SQL() {
            {
                SELECT("*");
                FROM("BOOKS");
                if(searchable.getName() != null) {
                    WHERE("NAME = #{name}");
                    if(searchable.getIssn() != null) {
                        OR();
                        WHERE("ISSN = #{issn}");
                    }
                }
                if(searchable.getOrderParam() != null) {

                    ORDER_BY(searchable.getOrderParam() + " DESC");
                }
            }
        }.toString();
    }
}
