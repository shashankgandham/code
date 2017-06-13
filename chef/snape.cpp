<pre>#include&lt;stdio.h&gt;
#include&lt;math.h&gt;

int main()
{

int i,n;
float a,b;

scanf(&quot;%d&quot;,&amp;n);

	for(i=0;i&lt;n;i++)
	{
	scanf(&quot;%f %f&quot;,&amp;a,&amp;b);
	printf(&quot;%f %f\n&quot;,sqrt(b*b-a*a),sqrt(b*b+a*a));
	}
return 0;
}

</pre>