while [ 1 ] ; do echo "100 000 d :";
		 /usr/bin/time -p ./../client/client "$1" "`cat 100000_d`" ;
		 echo "10 000 c :";
		 /usr/bin/time -p ./../client/client "$1" "`cat 10000_c`";
		 echo "1000 b :";
		 /usr/bin/time -p ./../client/client "$1" "`cat 1000_b`";
		 echo "100 a :";
		 /usr/bin/time -p ./../client/client "$1" "`cat 100_a`";
		 echo "Some unicode :";
		 /usr/bin/time -p ./../client/client "$1" "`cat special`";
		 echo "Man man :";
		 /usr/bin/time -p ./../client/client "$1" "`man man`";
		 echo "";
done
