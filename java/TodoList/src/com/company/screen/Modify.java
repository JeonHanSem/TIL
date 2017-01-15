package com.company.screen;

import com.company.Lumberroom;
import com.company.Todo;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

/**
 * todo 수정
 */
public class Modify implements View, Setting {
    private Todo todo;
    private Lumberroom lumberroom;
    private String title;
    private String content;
    private String deadLine;

    Modify(int todoIdx){
        lumberroom = new Lumberroom(todoIdx);
        todo = lumberroom.loadTodo(todoIdx);
    }

    @Override
    public void printView() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("MODIFY");
        System.out.print("Title : ");
        title = scanner.nextLine();
        System.out.print("Content : ");
        content = scanner.nextLine();
        System.out.print("DeadLine(yyyy.MM.dd) : ");
        deadLine = scanner.next();

        setting();

        View detail = new Detail(todo.getTodoIdx());
        detail.printView();
    }

    @Override
    public void setting() {
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy.MM.dd");
        Date date = new Date();
        String time = simpleDateFormat.format(date);

        todo.setTitle(title);
        todo.setContent(content);
        todo.setModifyDate(time);
        todo.setDeadLine(deadLine);

        lumberroom.saveTodo(todo, todo.getState());
    }
}
