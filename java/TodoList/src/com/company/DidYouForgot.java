package com.company;

import com.company.screen.View;
import com.company.screen.Yet;

/**
 * Main
 */

public class DidYouForgot extends ViewController{

    public static void main(String[] args) {
        ViewController viewController = new ViewController();
        View yet = new Yet();
        viewController.print(yet);
    }
}
