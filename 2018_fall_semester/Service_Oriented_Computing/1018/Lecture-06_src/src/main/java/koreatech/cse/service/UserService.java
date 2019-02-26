package koreatech.cse.service;

import koreatech.cse.domain.User;
import koreatech.cse.repository.UserMapper;
import org.springframework.stereotype.Service;

import javax.inject.Inject;
import java.util.Date;

@Service
public class UserService {
    @Inject
    private UserMapper userMapper;

    public Boolean signup(User user) {
        if(user.getEmail() == null || user.getPassword() ==  null)
            return false;

        userMapper.insert(user);

        System.out.println("User created: " + new Date());
        return true;
    }
}
