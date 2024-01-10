clc
clear all

data=importdata("data.txt");
% data1=importdata("data4.txt");
% data2=importdata("data41.txt");
% data3=importdata("dataplatte.txt");
% 
% 
pitch=data(:,1);
yaw=data(:,2);
roll=data(:,3);
% 
% pitch1=data1(:,1);
% yaw1=data1(:,2);
% roll1=data1(:,3);
% 
% pitch2=data2(:,1);
% yaw2=data2(:,2);
% roll2=data2(:,3);
% 
% pitch3=data3(:,1);
% yaw3=data3(:,2);
% roll3=data3(:,3);
% 
figure(1)
plot(pitch);
figure(2)
plot(yaw);
figure(3)
plot(roll);
% 
% 
% maxvec=[max(pitch) max(yaw) max(roll)];
% minvec=[min(pitch) min(yaw) min(roll)];
% 
% maxvec1=[max(pitch1) max(yaw1) max(roll1)];
% minvec1=[min(pitch1) min(yaw1) min(roll1)];
% 
% maxvec2=[max(pitch2) max(yaw2) max(roll2)];
% minvec2=[min(pitch2) min(yaw2) min(roll2)];
% 
% maxvec3=[max(pitch3) max(yaw3) max(roll3)];
% minvec3=[min(pitch3) min(yaw3) min(roll3)];
% 
% diff=maxvec-minvec
% diff1=maxvec1-minvec1
% diff2=maxvec2-minvec2
% diff3=maxvec3-minvec3