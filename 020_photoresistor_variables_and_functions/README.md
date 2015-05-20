This heavily-commented code shows you how to use `Spark.function` to create and register a function with the cloud. By telling the cloud "led on" you will be able to turn the LED on, and by telling it "led off" you can tell it to turn the LED off.

Meanwhile, the photoresistor will be putting its values into a variable called `analogvalue`. We also registered this variable to the cloud with `Spark.variable`, and now we can find out the value of that variable whenever we want to.

When we register a function or variable, we're basically making a space for it on the internet, similar to the way there's a space for a website you'd navigate to with your browser. Thanks to the REST API, there's a specific address that identifies you and your device. You can send requests, like `GET` and `POST` requests, to this URL just like you would with any webpage in a browser.

Remember the last time you submitted a form online? You may not have known it, but the website probably sent a `POST` request with the info you put in the form over to another URL that would store your data. We can do the same thing to send information to your device, telling it to turn the LED on and off.

Open a text editor and save the HTML code at the bottom of the example on the right as a .html file.

Edit the code in your text file so that "your-device-ID-goes-here" is your actual device ID, and "your-access-token-goes-here" is your actual access token. These things are accessible through your IDE at [build.particle.io](http://build.particle.io). Your device ID can be found in your Devices drawer (the crosshairs) when you click on the device you want to use, and your access token can be found in settings (the cogwheel).

Open that `.html` file in a browser. You'll see a very simple HTML form that allows you to select whether you'd like to turn the LED on or off.

When you click "Do it!" you are posting information to the URL `https://api.particle.io/v1/devices/your-device-ID-goes-here/led?access_token=your-access-token-goes-here`. The information you give is the `args`, or argument value, of `on` or `off`. This hooks up to your `Spark.function` that we registered with the cloud in our firmware, which in turn sends info to your device to turn the LED on or off.

You'll get some info back after you submit the page that gives the status of your device and lets you know that it was indeed able to post to the URL. If you want to go back, just click "back" on your browser.


If you are using the command line, you can also turn the LED on and off by typing:

`particle call device_name led on`

and

`particle call device_name led off`

Remember to replace `device_name` with either your device ID or the casual nickname you made for your device when you set it up.

This does the same thing as our HTML page, but with a more slick interface.


We can also check the value of the Photoresistor as we turn the LED on and off. Just as a URL was generated for our `led` function, a URL was generated for our `analogwrite` variable.

Try going to the URL:

`https://api.particle.io/v1/devices/your-device-ID-goes-here/analogvalue?access_token=your-access-token-goes-here`

That will give you an (albeit ugly) output of the value of your photoresistor, as read by your device.

You can also check out this value by using the command line. Type:

`particle variable get device_name analogvalue`

and make sure you replace `device_name` with either your device ID or the casual nickname you made for your device when you set it up.
