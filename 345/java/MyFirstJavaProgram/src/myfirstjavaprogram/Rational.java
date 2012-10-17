/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package myfirstjavaprogram;


/**
 *
 * @author dsteil
 */
public class Rational implements Comparable<Rational>
{
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

    @Override
    public int compareTo(Rational t) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
    
    /**
     *
     * @return
     */
    @Override
    public boolean equals(Object rValue)
    {
        return false;
    }
    
}
