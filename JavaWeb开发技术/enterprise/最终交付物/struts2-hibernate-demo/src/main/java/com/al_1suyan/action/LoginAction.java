package com.al_1suyan.action;

import com.opensymphony.xwork2.ModelDriven;
import com.al_1suyan.domain.Student;
import com.al_1suyan.service.StudentService;
import com.al_1suyan.service.impl.StudentServiceImpl;

public class LoginAction implements ModelDriven<Student> {
    private StudentService studentService =new StudentServiceImpl();
    private Student student =new Student();
    private String msg;
    private String getMsg(){
        return msg;
    };
    public Student getModel(){
        return student;
    }
    public String execute() {
        System.out.println(student);
        String username = student.getUsername();
        String password = student.getPassword();

        Student student1 = studentService.findByUsername(username);
        if (student1 == null) {
            msg="用户名不存在";
            return "fail";
        } else {
            if (student1.getPassword().equals(password)) {
                return "success";
            } else {
                msg="密码错误";
                return "fail";
            }
        }
    }
}

