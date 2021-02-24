# HallSensor RPM meter using Machine Learning with EdgeImpulse
The project is a section of the training course "Introduction to Embedded Machine Learning", by hawn Hymel, the main instructor in collaboration with Edge Impulse

# Intro

I chose a simple 12v fan for measuring the rotational velocity in 4 states (OFF, LOW, MED, HIGH), for achieving that I attached a magnet on a blade of the fan and I added up a hall sensor for measuring the magnetism when the magnet gets closer to the sensor.

![WhatsApp Image 2021-02-22 at 1 09 07 PM](https://user-images.githubusercontent.com/46487846/108938342-886a7100-7615-11eb-8d7e-b430da49ac7f.jpeg)

Here I used an ESP32 as a functional microcontroller for obtaining the hall sensor values and collecting the data, using some filtering techniques and data synthesis inside of the code in the microcontroller I obtained different waveforms in those 4 states.

![OFF](https://user-images.githubusercontent.com/46487846/108938068-024e2a80-7615-11eb-9e41-62b029ecdaf8.PNG)

![LOW](https://user-images.githubusercontent.com/46487846/108938064-01b59400-7615-11eb-8bf6-a701101ec39b.PNG)

![MED](https://user-images.githubusercontent.com/46487846/108938065-024e2a80-7615-11eb-8056-75ee079e24fe.PNG)

![HIGH](https://user-images.githubusercontent.com/46487846/108938063-011cfd80-7615-11eb-8680-77f0432a8ae8.PNG)

I used the Edge Impulse Data Forwarder which helped me to connect the ESP32 directly to Edge Impulse, I collected almost 4 minutes of data dividing equally each label used. Then I created my impulse using spectral features where at the beginning I obtained some random points in the plots, then I understood that my samples are not too repetitive through the data sample, so I had to modify my window size to a big one to adjust the period of the signal, after struggling with the period of the data, I obtained some interesting forms in my feature explorer window.

![f](https://user-images.githubusercontent.com/46487846/108938070-02e6c100-7615-11eb-8e84-ccbc4ae03d84.PNG)

Once I got the spectral features, I proceeded with the NN classifier using two layers with almost 15 neurons in total (5 neurons on the first layer and 10 neurons on the second layer). obtaining a pretty accurate model.

![T](https://user-images.githubusercontent.com/46487846/108938069-024e2a80-7615-11eb-975a-8f98aef2511d.PNG)

I understood that different data samples might have some crucial characteristics to regard while analyzing the signals, in my case, the period of the lower and medium signals have affected my results in the beginning, finally, I applied the anomaly detection into the project and after programming the microcontroller I identified that it detects accurately the different states of the fan and it detects anomalies when I turn the fan manually with my hand.

![WhatsApp Image 2021-02-22 at 1 04 10 PM](https://user-images.githubusercontent.com/46487846/108938339-87d1da80-7615-11eb-9257-de48ba983105.jpeg)


