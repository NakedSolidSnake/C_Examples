all: daemonEx.out appnoparams.out appwithparams.out

daemonEx.out: 
	gcc -g daemon.c -o daemonEx.out	

appnoparams.out: 
	gcc -g appnoparams.c -o appnoparams.out

appwithparams.out:
	gcc -g appwithparams.c -o appwithparams.out

clean:
	rm -rf *.out