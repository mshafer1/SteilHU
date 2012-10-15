/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package myfirstjavaprogram;

/**
 *
 * @author dsteil
 */
public class Rational {
    public int n;
    public int d;
    
    Rational(int n, int d)
    {
        this.n = n;
        this.d = d;
    }

    Rational()
    {
        n = 0;
        d = 1;
    }
    
    public void display()
    {
        System.out.print(n);
        System.out.print("/");
        System.out.println(d);
    }
}
