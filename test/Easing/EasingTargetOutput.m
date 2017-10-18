% @file
% @ingroup 	minlib
% 
% @brief 		Generates the Expected Target Output for Easing using Octave
%
% @author		Nathan Wolek
% @copyright	Copyright (c) 2017 Nathan Wolek
% @license		This project is released under the terms of the MIT License.

clear

% NOTE: in developing the code for this file, I consulted the following:
% https://github.com/warrenm/AHEasing/blob/master/AHEasing/easing.c
% https://github.com/Cycling74/min-lib/blob/master/include/c74_lib_easing.h

% Variables at the top are used to vary the target outputs.
% - samples_to_output controls the number of samples in each target output matrix.
samples_to_output = 64;

% 1 - initialize all matrices to hold values generated
input_ramp = double (1 : samples_to_output);
output_linear = double (1 : samples_to_output);
output_in_back = double (1 : samples_to_output);
output_in_out_back = double (1 : samples_to_output);
output_out_back = double (1 : samples_to_output);
output_out_bounce = double (1 : samples_to_output);
output_in_bounce = double (1 : samples_to_output);
output_in_out_bounce = double (1 : samples_to_output);
output_in_circular = double (1 : samples_to_output);
output_out_circular = double (1 : samples_to_output);

% 2 - define any functions used to generate values
function retval = in_out_back(inval)
	retval = 0.0; 
	if (inval < 0.5)
		f = 2 * inval;
		retval = 0.5 * (f * f * f - f * sin(f * pi));
	else
		f = (1 - (2*inval - 1));
		retval = 0.5 * (1 - (f * f * f - f * sin(f * pi))) + 0.5;
	endif
endfunction

function retval = out_back(inval)
	retval = 0.0;
	f = (1 - inval);
	retval = 1 - (f * f * f - f * sin(f * pi));
endfunction

function retval = out_bounce(inval)
	retval = 0.0;
	if (inval < 4/11.0)
		retval = (121 * inval * inval)/16.0;
	elseif (inval < 8/11.0)
		retval = (363/40.0 * inval * inval) - (99/10.0 * inval) + 17/5.0;
	elseif(inval < 9/10.0)
		retval = (4356/361.0 * inval * inval) - (35442/1805.0 * inval) + 16061/1805.0;
	else
		retval = (54/5.0 * inval * inval) - (513/25.0 * inval) + 268/25.0;
	endif
endfunction

function retval = in_bounce(inval)
	retval = 1 - out_bounce(1 - inval);;
endfunction

function retval = in_out_bounce(inval)
	retval = 0.0;
	if (inval < 0.5)
		retval = 0.5 * in_bounce(inval*2);
	else
		retval = 0.5 * out_bounce(inval * 2 - 1) + 0.5;
	endif
endfunction

% 3 - iterate through loop to fill matrices
for i = 1:samples_to_output
	% NW: our formula for input_ramp is constructed so that 0 and 1 will be included
	x = (i-1) / (samples_to_output-1);
	input_ramp(i) = x;
	output_linear(i) = x;
	output_in_back(i) = x * x * x - x * sin(x * pi);
	output_in_out_back(i) = in_out_back(x);
	output_out_back(i) = out_back(x);
	output_out_bounce(i) = out_bounce(x);
	output_in_bounce(i) = in_bounce(x);
	output_in_out_bounce(i) = in_out_bounce(x);
	output_in_circular(i) = 1 - sqrt(1 - (x * x));
	output_out_circular(i) = sqrt((2 - x) * x);
endfor

% 4 - write output values to disk
save expectedOutput.mat input_ramp
save -append expectedOutput.mat output_linear
save -append expectedOutput.mat output_in_back
save -append expectedOutput.mat output_in_out_back
save -append expectedOutput.mat output_out_back
save -append expectedOutput.mat output_out_bounce
save -append expectedOutput.mat output_in_bounce
save -append expectedOutput.mat output_in_out_bounce
save -append expectedOutput.mat output_in_circular
save -append expectedOutput.mat output_out_circular