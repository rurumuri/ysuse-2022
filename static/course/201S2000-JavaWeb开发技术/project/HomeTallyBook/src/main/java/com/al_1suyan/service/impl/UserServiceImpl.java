package com.al_1suyan.service.impl;

import com.al_1suyan.dao.HomeCostDao;
import com.al_1suyan.pojo.User;
import com.al_1suyan.service.UserService;
import com.al_1suyan.utils.DBUtils;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

public class UserServiceImpl implements UserService {
    public int updatesql(String query) {
        Connection conn = DBUtils.getConn();//获取连接对象
        Statement state = null;
        try {
            state = conn.createStatement();
            return state.executeUpdate(query);
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            DBUtils.close(state, conn);
        }
        return -1;
    }

    //添加该用户到数据库
    public int add(User user) {
        String query = String.format("insert into user(username,password) values('%s','%s')", user.getUsername(), user.getPassword());
        return updatesql(query);
    }

    //删除该用户
    public int delete(User user) {
        String query = String.format("delete from user where username='%s'", user.getUsername());
        //还得同比删除消费记录
        HomeCostDao homeCostDao = new HomeCostDao(user.getUsername());
        int res = homeCostDao.deleteByUserName(user.getUsername());
        if (res == -1) return res;
        return updatesql(query);
    }

    //修改密码
    public int update(User user) {
        String query = String.format("update user set password='%s' where username='%s'", user.getPassword(), user.getUsername());
        System.out.println(query);
        return updatesql(query);
    }

    //获取所以用户
    public List<User> list() {
        String query = String.format("select * from user");
        List<User> users = new ArrayList<>();
        Connection connection = DBUtils.getConn();
        Statement statement = null;
        ResultSet resultSet = null;
        try {
            statement = connection.createStatement();
            resultSet = statement.executeQuery(query);
            while (resultSet.next()) {
                String username = resultSet.getString("username");
                String password = resultSet.getString("password");
                User user = new User(username, password);
                users.add(user);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            DBUtils.close(resultSet, statement, connection);
        }
        return users;
    }

    public User getUserByUsername(String username) {
        String query = String.format("select * from user where username='%s'", username);
        User user = null;
        Connection connection = DBUtils.getConn();
        Statement statement = null;
        ResultSet resultSet = null;
        try {
            statement = connection.createStatement();
            resultSet = statement.executeQuery(query);
            if (resultSet.next()) {
                user = new User(resultSet.getString("username"), resultSet.getString("password"));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            DBUtils.close(resultSet, statement, connection);
        }
        return user;
    }

    public User getUserByUser(User user) {
        String query = String.format("select * from user where username='%s' and password='%s'", user.getUsername(), user.getPassword());
        User user1 = null;
        Connection connection = DBUtils.getConn();
        Statement statement = null;
        ResultSet resultSet = null;
        try {
            statement = connection.createStatement();
            resultSet = statement.executeQuery(query);
            if (resultSet.next()) {
                user1 = new User(resultSet.getString("username"), resultSet.getString("password"));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            DBUtils.close(resultSet, statement, connection);
        }
        return user1;
    }

    public List<User> query(String keyword) {
        String query = "select * from user where username like '%" + keyword + "%'";
        List<User> users = new ArrayList<>();
        Connection connection = DBUtils.getConn();
        Statement statement = null;
        ResultSet resultSet = null;
        try {
            statement = connection.createStatement();
            resultSet = statement.executeQuery(query);
            while (resultSet.next()) {
                String username = resultSet.getString("username");
                String password = resultSet.getString("password");
                User user = new User(username, password);
                users.add(user);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            DBUtils.close(resultSet, statement, connection);
        }
        return users;
    }

}
