package com.company.screen;

import com.company.Lumberroom;
import com.company.Todo;
import com.company.ViewController;

import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;

/**
 * 해야할 todo list
 */
public class Yet extends ViewController implements View, Menu{
    @Override
    public void printView() {
        Lumberroom lumberroom = new Lumberroom();
        List<Todo> list = lumberroom.listTodo(YET);

        System.out.println("TodoList(YET)");
        for(Todo todo:list){
            System.out.println(todo.getTodoIdx() + ". " + todo.getTitle());
        }
        menuView();
    }

    @Override
    public void menuView() {
        System.out.println("---------------------------------------\na. new\tb. detail\tc. doneList\tx. exit");
        System.out.print("Choose the menu : ");
        Scanner scanner = new Scanner(System.in);
        String signal = scanner.next();

        View view;
        if(signal.equals("a")){
            view = new New();
            print(view);
        }else if(signal.equals("b")){
            try {
                System.out.print("Choose the number : ");
                int todoIdx = scanner.nextInt();
                view = new Detail(todoIdx);
                print(view);
            }catch (InputMismatchException e){
                System.out.println("WrongType");
                menuView();
            }catch (NullPointerException e){
                System.out.println("Empty todo");
                menuView();
            }
        }else if(signal.equals("c")){
            view = new Done();
            print(view);
        }else if(signal.equals("x")){
            return;
        }else{
            menuView();
        }
    }
}