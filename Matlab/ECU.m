x= 0:0.01:2*pi;
y=2047+2047*sin(x);
id3 = '0CFFF348';
dlc = '08';

x1= 0:0.01:2*pi;
y1=2047+2047*sin(2*x);

x9= 0:0.01:2*pi;
y9=2048+2048*sin(4*x);

r = 2047*rand(1,length(y));

fid = fopen('HUB_6.txt', 'w+'); 
   for i=1:length(z)
        fprintf(fid,'%s%s%04x%04x%04x%04x\r\n',id3,dlc,round(y(i)),round(y1(i)),round(y9(i)),round(r(i)));
   end
fclose(fid);



