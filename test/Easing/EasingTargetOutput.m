% @file
% @ingroup 	minlib
% 
% @brief 		Generates the Expected Target Output for Easing using Octave
%
% @author		Nathan Wolek
% @copyright	Copyright (c) 2017 Nathan Wolek
% @license		This project is released under the terms of the MIT License.

clear

% Variables at the top are used to vary the target outputs.
% - samples_to_output controls the number of samples in each target output matrix.
samples_to_output = 64;

% 1 - initialize all matrices to hold values generated
input_ramp = double (1 : samples_to_output);
output_linear = double (1 : samples_to_output);
output_in_back = double (1 : samples_to_output);

% 2 - define any functions used to generate values

% 3 - iterate through loop to fill matrices
for i = 1:samples_to_output
	% NW: our formula for input_ramp is constructed so that 0 and 1 will be included
	x = (i-1) / (samples_to_output-1);
	input_ramp(i) = x;
	output_linear(i) = x;
	output_in_back(i) = x * x * x - x * sin(x * pi);
	
endfor

% 4 - write output values to disk
save expectedOutput.mat input_ramp
save -append expectedOutput.mat output_linear
save -append expectedOutput.mat output_in_back