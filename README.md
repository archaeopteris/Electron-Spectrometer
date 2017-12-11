# Electron-Trajectory-Tracker
Program calculates complex trajectory of electron beam (or any other charged particles) in uneven magnetic fields.
Data was used for construction of a mass spectrometer for ![alt text][beta]	 radiation from ![alt text][Sr90] isotope to separate them by energy and have a collimated monochromatic radiation source.
Program 'Tracker.cpp' also performs Monte Carlo simulation to calculate the energy distribution on the output of the device and
energy deviation in obtained collimated monochromatic electron beam.

Project was done at Alikhanyan National Science Laboratory as part of a Diploma Work for acquiring bachelor's degree.

### Electron beam Source
Source beam from Strontium 90 has a gaussian angle distribution on input of the device.

### Output Beam
Collimators on the output of the device are made from permalloy and are 100mm long.
Collimators for 1 and 1.5 MeV beams are 5mm width.
Collimator for 2 MeV beams are 10mm width.

Monte Carlo simulation results for collimated output beams with 1, 1.5 and 2 MeV mean energies.

Energy distribution in 1 MeV beam:
![alt text][1mev]

Energy distribution in 1.5 MeV beam:
![alt text][1.5mev]

Energy distribution in 2 MeV beam:
![alt text][2mev]



[beta]: https://latex.codecogs.com/gif.latex?\beta&space;^{-}

[Sr90]: https://latex.codecogs.com/gif.latex?Sr^{90}

[1mev]: https://github.com/archaeopteris/Electron-Trajectory-Tracker/blob/master/Maps%20and%20Graphs/1MeV.png?raw=true
[1.5mev]: https://github.com/archaeopteris/Electron-Trajectory-Tracker/blob/master/Maps%20and%20Graphs/1.5MeV.png?raw=true
[2mev]: https://github.com/archaeopteris/Electron-Trajectory-Tracker/blob/master/Maps%20and%20Graphs/2MeV.png?raw=true
