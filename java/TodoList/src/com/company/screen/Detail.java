package com.company.screen;

import com.company.Lumberroom;
import com.company.Todo;
import com.company.ViewController;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

/**
 * todo 상세보기
 */
public class Detail extends ViewController implements View, Menu, Setting {
    private Lumberroom lumberroom;
    private Todo todo;

    Detail(int todoIdx) {
        lumberroom = new Lumberroom(todoIdx);
        todo = lumberroom.loadTodo(todoIdx);
    }

    @Override
    public void printView() {
        System.out.println("CreateTime : " + todo.getCreateDate());
        System.out.println("ModifyTime : " + todo.getModifyDate());
        System.out.println("Title : " + todo.getTitle());
        System.out.println("Content : " + todo.getContent());
        System.out.println("DeadLine : " + todo.getDeadLine());
        if(todo.getState() == YET){
            System.out.println("State : YET");
        }else if(todo.getState() == DONE){
            System.out.println("State : DONE");
            System.out.println("CompleteTime : " + todo.getCompleteDate());
        }

        menuView();
    }

    @Override
    public void menuView() {
        System.out.println("---------------------------------------\na. complete\tb. modify\tc. delete\td. yetList");
        System.out.print("Choose the menu : ");
        Scanner scanner = new Scanner(System.in);
        String signal = scanner.next();

        View view;
        if(signal.equals("a")){
            setting();
            printView();
        }else if(signal.equals("b")) {
            view = new Modify(todo.getTodoIdx());
            print(view);
        }else if(signal.equals("c")){
            view = new Delete(todo.getTodoIdx());
            print(view);
        }else if(signal.equals("d")){
            view = new Yet();
            print(view);
        }else{
            menuView();
        }
    }

    @Override
    public void setting() {
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy.MM.dd");
        Date date = new Date();
        String time = simpleDateFormat.format(date);

        todo.setCompleteDate(time);

        lumberroom.saveTodo(todo, DONE);
    }
}
