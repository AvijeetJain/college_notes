rng(0);
N=10^5;

h1=(randn(1,N)+ 1i*randn(1,N))/sqrt(2);
h2=(randn(1,N)+ 1i*randn(1,N))/sqrt(2);
h3=(randn(1,N)+ 1i*randn(1,N))/sqrt(2);

SNR_dB=-8:2:30;

SNR=10.^(SNR_dB/10);
no=10;
pt=SNR*no;

Pt=10*log10(pt);
p=length(pt);

p1=zeros(1,p);
p2=zeros(1,p);
p3=zeros(1,p);

rate=1;

for u =1:p
    gamma1=pt(u)*abs(h1).^2/no;
    gamma2=pt(u)*abs(h2).^2/no;
    gamma3=pt(u)*abs(h3).^2/no;
    
    gamma2=max(gamma1,gamma2);
    gamma3=max(gamma1,max(gamma2,gamma3));
    R3=log2(1+gamma3);
    R2=log2(1+gamma2);
 

    for k =1:N
        if R3(k)<rate
            p1(u)=p1(u)+1;
        end
        if R2(k)<rate
            p2(u)=p2(u)+1;
        end
        
    end
end

theoretical_pout=1-exp(-no*(2^rate-1)./pt);
pout1=p1/N;
pout2=p2/N;

figure;

semilogy(Pt,theoretical_pout,'-','LineWidth',2);
hold on;
semilogy(Pt,pout2,'o','LineWidth',2);
hold on;
semilogy(Pt,pout1,'*','LineWidth',2)


xlabel=('Transmit power(dB)');
ylabel=("Outage probability");
grid on;
legend("Theoretical ","Simulated2","Simulated3");