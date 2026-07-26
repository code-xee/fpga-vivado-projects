fileID =  fopen('DATA_NOISE2.h','w');
fprintf(fileID,strcat('int  input_data[',num2str(1000),'] ={\n'));
fprintf(fileID,'%d,\n', y_fix(1:1000-1));
fprintf(fileID,'%d};\n',y_fix(1000));
fclose(fileID);