package com.company.screen;

import com.company.Lumberroom;
import com.company.Todo;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

/**
 * todo 생성
 */
public class New implements View, Setting {
    private String title;
    private String content;
    private String deadLine;

    @Override
    public void printView() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("NEW");
        System.out.print("Title : ");
        title = scanner.nextLine();
        System.out.print("Content : ");
        content = scanner.nextLine();
        System.out.print("DeadLine(yyyy.MM.dd) : ");
        deadLine = scanner.next();

        setting();

        View yet = new Yet();
        yet.printView();
    }

    @Override
    public void setting() {
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy.MM.dd");
        Date date = new Date();
        String time = simpleDateFormat.format(date);

        Todo todo = new Todo();
        todo.setTitle(title);
        todo.setContent(content);
        todo.setCreateDate(time);
        todo.setModifyDate(time);
        todo.setDeadLine(deadLine);

        Lumberroom lumberroom = new Lumberroom();
        lumberroom.saveTodo(todo,YET);
    }
}
