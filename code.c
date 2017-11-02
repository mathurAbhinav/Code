import java.awt.*;
import java.awt.event.*;
import java.applet.*;
import javax.swing.*;

/*
<object code="RectApplet.class" width=400 height=200>
</object>
*/

public class RectApplet extends JApplet
{
	int x,y,p,q;
	JButton j1,j2,j3,j4;
	String s="Rect";

	public void start()
	{
		setLayout(new FlowLayout());
		j1 = new JButton("rect");
		j2 = new JButton("circle");
		j3 = new JButton("arc");
		j4 = new JButton("line");
		add(j1);
		add(j2);
		add(j3);
		add(j4);

		j1.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent ae)
			{
				s="rect";
			}
		});

		j2.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent ae)
			{
				s="circle";
			}
		});

		j3.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent ae)
			{
				s="arc";
			}
		});

		j4.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent ae)
			{
				s="line";
			}
		});

		addMouseListener(new MouseAdapter()
		{
			public void mousePressed(MouseEvent me)
			{
				x=me.getX();
				y=me.getY();
			}
		});

		addMouseMotionListener(new MouseMotionAdapter()
		{
			public void mouseDragged(MouseEvent me)
			{
				p=me.getX();
				q=me.getY();
				repaint();
			}
		});
	}

	public void paint(Graphics g)
	{
		super.paint(g);
		g.setColor(Color.blue);

		if(s=="rect")
			g.fillRect(x,y,p-x,q-y);
		else if(s=="circle")
			g.fillOval(x,y,p-x,q-y);
		else if(s=="arc")
			g.fillArc(x,y,p-x,q-y,0,120);
		else if(s=="line")
			g.drawLine(x,y,p,q);
	}
}
