## 10/25
- Began rewiring today by completely scrapping the external breadboard, migrating pulldown resistors to the internal breadboard
- Started soldering clusters of identically-routed wires together
- Issues-- it still looks messy


## 10/27
- Continued rewiring; extended several signal wires from buttons
- Tested with program, numerous false signals sent
- False signals originating from both analog inputs and digital inputs
- Will consult Tim, verify connections


## 10/30-31
- Checking individual connections, attempting to find shorted or invalid connections
- +5v bus verified
- Ground bus verified, but some resistors insufficiently grounded
- Resolving
- current-limited +5v bus verified
- Switch/button isolation verified
- Testing buttons alone
- Buttons functioning properly
- Testing potentiometers
- Potentiometers not reading properly, switching to other arduino to verify integrity of ADC
- Similar issues, changing to known working potentiometer
- Potentiometer working
- Testing mounted potentiometers using multimeter
- Mounted potentiometers verified non-functional. Must have burned them out
