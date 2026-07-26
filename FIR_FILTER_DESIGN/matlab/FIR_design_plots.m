clc
clear all;

Fs = 200e3 ;
Ts = 1/Fs ;
dt = 0: Ts : 5e-3-Ts ;

f1=1e3;
f2=20e3;
f3=30e3;

y= 5*sin(2*pi*f1*dt) + 5*sin(2*pi*f2*dt) + 10*sin(2*pi*f3*dt);

y_fix = round(y*2^15)
%plot(dt,y) ;

nfft= length(y) ;
nfft2 = 2.^nextpow2(nfft) ;

fy= fft(y,nfft2) ;
fy= fy(1:nfft2/2);

xfft = Fs * (0:nfft2/2-1)/nfft2 ;

plot(xfft , abs(fy/max(fy))) ;

cut_off = 1.5e3 /Fs /2 ;
order = 32 ;

h=fir1(order, cut_off);
fh = fft(h,nfft2);
fh =fh(1:nfft2/2);

freqz(h)

y_f = filter(h,1,y) ;

mul = fh.* fy ;

con = conv(y,h) ;

subplot(3,2,1)
plot(dt,y);
title('Input signal y(t): 1 kHz + 20 kHz + 30 kHz tones');
xlabel('Time (s)'); ylabel('Amplitude');
%subplot(3,2,3)
%stem(h)
subplot(3,2,5)
plot(con)
title('Filtered output: conv(y,h) - only 1 kHz tone remains');
xlabel('Sample index'); ylabel('Amplitude');


subplot(3,2,2)
plot(xfft , abs(fy/max(fy)))
title('Input spectrum |Y(f)| (normalized) - 3 peaks');
xlabel('Frequency (Hz)'); ylabel('|Y(f)| / max');
subplot(3,2,4)
plot(xfft , abs(fh/max(fh)))
title('Filter response |H(f)| (normalized) - lowpass');
xlabel('Frequency (Hz)'); ylabel('|H(f)| / max');
subplot(3,2,6)
plot(abs(mul))
title('Filtering in frequency domain: |H(f) x Y(f)|');
xlabel('FFT bin'); ylabel('Magnitude');
