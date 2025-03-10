package com.al_1suyan.action;

import com.opensymphony.xwork2.ModelDriven;
import com.al_1suyan.domain.User;
import org.apache.struts2.ServletActionContext;


public class LoginAction implements ModelDriven<User> {
    private User user=new User();
    @Override
    public User getModel() {
        // TODO Auto-generated method stub
        return user;
    }
    public String execute() {
        System.out.println(user);
        if (user.getUsername().equals("admin") && user.getPassword().equals("123456")){
            ServletActionContext.getRequest().getSession().setAttribute("user", user);
            return "success";
        }
        return "fail";
    }

}

