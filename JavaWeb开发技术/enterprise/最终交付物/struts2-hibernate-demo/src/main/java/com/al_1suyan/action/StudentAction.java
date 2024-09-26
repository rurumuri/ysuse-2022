package com.al_1suyan.action;

import com.opensymphony.xwork2.ModelDriven;
import com.al_1suyan.domain.Student;
import com.al_1suyan.service.StudentService;
import com.al_1suyan.service.impl.StudentServiceImpl;
import org.apache.struts2.ServletActionContext;

import java.util.List;

public class StudentAction implements ModelDriven<Student> {
    private StudentService studentService =new StudentServiceImpl();

    private String msg;
    public String getMsg(){
        return msg;
    }
    private Student student =new Student();
    @Override
    public Student getModel(){

        return student;
    }
    public Student getUser(){
        return student;
    }
    public String login(){
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
    public String list(){
        String username = student.getUsername();
        List<Student> students = studentService.list(username);
        System.out.println(students);
        ServletActionContext.getRequest().setAttribute("list", students);
        return "list";
    }
    public String add(){
        System.out.println(student);
        Student student1 = studentService.findByUsername(student.getUsername());;
        if(student1 !=null){
            msg="用户已经存在";
            return "add";
        }else {
            boolean result = studentService.add(student);
            if (result) {
                return "toList";
            } else {
                msg = "用户新增失败";
                return "add";
            }
        }
    }
    public String findById(){
        Integer id = student.getId();
        student = studentService.findById(id);
        return "update";
    }
    public String update(){
        boolean result = studentService.update(student);
        return "toList";
    }
    public String del(){
        boolean result = studentService.delete(student);
        return "toList";
    }
}
