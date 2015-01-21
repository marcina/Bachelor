x= 0:0.01:2*pi;
y=2047+2047*sin(x);
id = '11FFF048';
dlc = '02';


x1= 0:0.01:2*pi;
y1=2047+2047*sin(2*x);
id1 = '11FFF148';
dlc1 = '02'


x9= 0:0.01:2*pi;
y9=2048+2048*sin(4*x);
id9 = '11FFFa48';
dlc9 = '02'

r = 2047*rand(1,length(y));
id3 = '11FFF348';
dlc3 = '02'

fid = fopen('HUB_1.txt', 'w+'); 
   for i=1:length(z)
        fprintf(fid,'%s%s%04x\r\n',id,dlc,round(y(i)));
        fprintf(fid,'%s%s%04x\r\n',id1,dlc1,round(y1(i)));
        fprintf(fid,'%s%s%04x\r\n',id9,dlc9,round(y9(i)));
        fprintf(fid,'%s%s%04x\r\n',id3,dlc3,round(r(i)));
   end
fclose(fid);



