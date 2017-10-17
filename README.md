 NCTU_DS_2017__Hw1
=====================
It is  homework 1 of data strcture  in NCTU
----------------
# 1.	Pseudo Code:
<pre>
1.While  input_file! =Null      
2.	Do 
		If(We obtain equals to “#”)
		Then infor_end=1;
		else ( We obtain !=”#”)
			if( infor_end equals to 1)
				then save the row to Data2D;
			else save the row to direction;
			ENDIF;
		ENDIF;
   Then save to Data2D   
   ENDWHILE
3.	 FOR j IN 0 TO direction.size()
		DO (read two values of every row in direction, and determine the max value, which is called max_push)
		FOR i IN 0 TO max_push
			DO (push data to temp_queue except two data which is compared);   
 		ENDFOR
    	ENDFOR
4.   	DO(Save chosen data to compar_a and compar_b matrix) 
	FOR iterator in compar_b.begin() TO compar_b.end()
		IF(the chosen data in compar_b equals to The first data of compare_a)
        		then (the data push front to compar_a );
	        else the data push back to compar_b;
		ENDIF
     	ENDFOR
5.	FOR i IN 0 TO max_push
  		DO(erase the begin of Data2D);
        ENDFOR
6.	IF(exchange equals to 0)
		Then( Push compar_a and then push temp_queue);
	Else (Push temp_queue and then push compar_a);
	ENDIF

</pre>


