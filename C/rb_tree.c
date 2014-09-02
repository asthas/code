#include <stdio.h>
#include <stdlib.h>
rb-insert(int t[], int z)
{
	int x,y;
	y=t[-1];
	x=t.root;

	while(x!=t.[-1])
	{	
		y=x;
		if z.key < x.key
			x=x.left;
		else
			x=x.right;

	}
	z.p=y;
	if(y == t[-1])
		t.root = z;
	else if (z.key < y.key)
	{
		y.left=z;
	}
	else
		y.right = z;
	z.left = t.nil;
	z.right = t.nil;
	z.color = red;
	rb-insert-fixup(t, z);
}

rb-insert-fixup(int t[], int z)
{
	while(z.p.color = red)
	{
		if(z.p == z.p.p.left)
		{
			y = z.p.p.right;
			if(y.color == red)
			{
				z.p.color = black;
				y.color = black;
				z.p.p.color = red;
				z = z.p.p;

			}
			elseif(z == z.p.right)
			{
				z=z.p;
				left-rotate(t, z)
			}
			z.p.color = black;
			z.p.p.color = red;
			right-rotate()
		}
	}
}

