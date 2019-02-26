package koreatech.cse.aop;

import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.*;

import java.util.Date;

@Aspect
public class AopTester {
    @Before("execution(* koreatech.cse.service.UserService.signup(..))")            //실행 전
    public void beforeMethod(JoinPoint joinPoint) {
        System.out.println("Before " + joinPoint.getSignature().getName() + ": " + new Date());         //실행 후
    }

    @After("execution(* koreatech.cse.service.UserService.signup(..))")
    public void afterMethod(JoinPoint joinPoint) {
        System.out.println("After " + joinPoint.getSignature().getName() + ": " + new Date());
    }

    @AfterReturning(pointcut = "execution(* koreatech.cse.service.UserService.signup(..))",         //실행 후 결과를 가지고 뭐를 하는 것
            returning= "result")
    public void afterReturningMethod(JoinPoint joinPoint, Object result) {
        System.out.println("After Returning " + joinPoint.getSignature().getName()
                + ": " + new Date() + ", Value = " + result);
    }

    @Around("execution(* koreatech.cse.service.UserService.signup(..))")            //before, after한번에 사용
    public void aroundMethod(ProceedingJoinPoint joinPoint) throws Throwable {
        System.out.println("@Around is running!");
        System.out.println("Before " + joinPoint.getSignature().getName());
        joinPoint.proceed();    //이거 실행이 전, 후를 나누는 기준이다.
        System.out.println("After " + joinPoint.getSignature().getName());
    }

}
