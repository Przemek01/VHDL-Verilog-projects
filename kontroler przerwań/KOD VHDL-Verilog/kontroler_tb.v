`timescale 1ns / 1ps


module kontroler_tb;
reg reset;
reg clk;
reg	[7:0] data_out;
wire [7:0] data_in;
reg [1:0] adres;
reg nr_w;
reg [4:0] irq_in;
wire irq_out;
integer plik_irq_in1,plik_irq_in2,plik_irq_in3,plik_irq_in4;
integer plik_wyniki;



	// Instantiate the Unit Under Test (UUT)
	irq_control uut (
.clk(clk),
.reset(reset),
.data_out(data_out),
.data_in(data_in),
.adres(adres),
.nr_w(nr_w),
.irq_in(irq_in),
.irq_out(irq_out)

	);
	
initial begin


plik_irq_in1 = $fopen("zbocze_data_irq.txt","r");
plik_irq_in2 = $fopen("poziom_data_irq.txt","r");
plik_irq_in3 = $fopen("zbocze_data_irq_maskowanie.txt","r");
plik_irq_in4 = $fopen("poziom_data_irq_maskowanie.txt","r");

  if(!plik_irq_in1) begin
$display("nie udalo sie otworzyc plikow zbocze_data_irq.txt");
$finish;
  end	
  
  if(!plik_irq_in2) begin
$display("nie udalo sie otworzyc plikow poziom_data_irq.txt");
$finish;
  end	
  
  if(!plik_irq_in3) begin
$display("nie udalo sie otworzyc plikow zbocze_data_irq_maskowanie.txt");
$finish;
  end	
  
  
  if(!plik_irq_in4) begin
$display("nie udalo sie otworzyc pliku poziom_data_irq_maskowanie.txt");
$finish;
  end	
  
  
  
end



	initial begin
		clk = 0;
      #5 reset = 0;
		#5 reset = 1;
		
plik_wyniki = $fopen("wyniki.txt","w");
if(!plik_wyniki) begin
$display("nie udalo sie otworzyc pliku");
$finish;
end		
		
      #5;
		while(! $feof(plik_irq_in1)) begin
            @(negedge clk);
            $fscanf(plik_irq_in1,"%h\n",irq_in[4:0]);
				
nr_w = 1;
adres = 'b01;
data_out = 'b00011111;
#2;
nr_w = 0;
adres = 'b10;
#2;
nr_w = 1;
adres = 'b11;
data_out = 'b00011111;
#2;
nr_w = 0;
adres = 'b01;
#2;
adres = 'b11;
				#2;
         end 


while(! $feof(plik_irq_in2)) begin
            @(negedge clk);
            $fscanf(plik_irq_in2,"%h\n",irq_in[4:0]);
				
nr_w = 1;
adres = 'b01;
data_out = 'b00000000;
#2;
adres = 'b11;
data_out = 'b00011111;
#2;
nr_w = 0;
adres = 'b01;
#2;
adres = 'b11;
#2;
adres = 'b10;
				#5;
         end 
			
			while(! $feof(plik_irq_in3)) begin
            @(negedge clk);
            $fscanf(plik_irq_in3,"%h\n",irq_in[4:0]);
				
nr_w = 1;
adres = 'b01;
data_out = 'b00011111;
#2;
nr_w = 0;
adres = 'b10;
#2;
nr_w = 1;
adres = 'b11;
data_out = 'b00000000;
#2;
nr_w = 0;
adres = 'b01;
#2;
adres = 'b11;
				#2;
         end 
			
			while(! $feof(plik_irq_in4)) begin
            @(negedge clk);
            $fscanf(plik_irq_in4,"%h\n",irq_in[4:0]);
				
nr_w = 1;
adres = 'b01;
data_out = 'b00000000;
#2;
adres = 'b11;
data_out = 'b00000000;
#2;
nr_w = 0;
adres = 'b01;
#2;
adres = 'b11;
#2;
adres = 'b10;
				#2;
         end 

$fclose(plik_irq_in1);
$fclose(plik_irq_in2);
$fclose(plik_irq_in3);
$fclose(plik_irq_in4);

$fclose(plik_wyniki);
$finish;
		
	end


always  #1 clk <= ~clk;

always @(posedge clk)
begin
#1;
$fwrite(plik_wyniki,"data_out = %h | data_in = %h | adres = %b | nr_w = %b | irq_in = %h | irq_out = %b \n",data_out[7:0],data_in[7:0],adres[1:0],nr_w,irq_in[4:0],irq_out);
end

	
endmodule

