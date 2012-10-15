/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package myfirstjavaprogram;

/**
 *
 * @author dsteil
 */
public class MyFirstJavaProgram {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int x = args.length;
        System.out.println("Hello");
        Rational r = new Rational();
        Rational r2 = null;
        r.display();
        
        String[] names = new String[100];
        for(int i = 0; i < 100; i++)
        {
            names[i]  = new String();
        }
        //r2.display();
    }
}
