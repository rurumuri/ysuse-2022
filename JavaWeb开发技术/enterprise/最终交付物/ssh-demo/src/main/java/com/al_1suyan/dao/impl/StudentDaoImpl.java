package com.al_1suyan.dao.impl;


import com.al_1suyan.dao.StudentDao;
import com.al_1suyan.domain.Student;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Repository;

import java.util.List;
@Repository
public class StudentDaoImpl implements StudentDao {
    @Autowired
    private SessionFactory sessionFactory;
    @Override
    public Student findByUsername(String username){
        Session session=sessionFactory.getCurrentSession();
        String hql="from Student where username=?";
        Student student =(Student)session.createQuery(hql).setString(0,username).uniqueResult();
        //session.close();
        return student;
    }
    @Override
    public List<Student> list(String username){
        Session session=sessionFactory.getCurrentSession();
        String hql="from Student where username like ?";
        List<Student> list=session.createQuery(hql).setString(0,"%"+username+"%").list();
        //session.close();
        return list;
    }
    @Override
    public boolean add(Student student){
        Session session=sessionFactory.getCurrentSession();
        session.save(student);
        return true;

    }
    @Override
    public Student findById(int id){
        Session session=sessionFactory.getCurrentSession();
        String hql="from Student where id=?";
        Student student =(Student)session.createQuery(hql).setInteger(0,id).uniqueResult();
        //session.close();
        return student;

    }
    @Override
    public boolean update(Student student){
        Session session=sessionFactory.getCurrentSession();
        session.update(student);
        return true;
    }
    public boolean delete(Student student){
        Session session=sessionFactory.getCurrentSession();
        session.delete(student);
        return true;
    }
}

