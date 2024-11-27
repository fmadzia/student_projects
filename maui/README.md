# Aplikacja do obliczania ilości, wysokości i głębokości schodów

Desktopowa i mobilna aplikacja do obliczania ilości, wysokości i głębokości schodów napisana w MAUI. Należy podać dostępną wysokość i dostępną głębokość a program wyliczy ilość schodów i wysokość i głębokość poszczególnych stopni według zalecanych przedziałów - od 14 cm do 19 cm dla wysokości i od 25 cm do 32 cm dla głębokości.

![image](https://github.com/user-attachments/assets/8f661a29-bb4f-457e-b733-5a3853c27b15)

```cs
const int minHeight = 14;
  const int maxHeight = 19;
  const int minDepth = 25;
  const int maxDepth = 32;

  public MainPage()
  {
    InitializeComponent();
  }

  private void Button_Clicked(object sender, EventArgs e)
  {
    var availableHeight = int.Parse(inputHeight.Text);
    var availableDepth = int.Parse(inputDepth.Text);

    if(availableHeight < minHeight || availableDepth < minDepth)
    {
      resultLayout.IsVisible = false;
      errorLabel.Text = "Za małe wartości";

      return;
    }

    for(int height = maxHeight; height >= minHeight; --height)
    {
      for(int depth = maxDepth; depth >= minDepth; --depth)
      {
        int stepsByHeight = availableHeight / height;
        int stepsByDepth = availableDepth / depth;

        if(stepsByHeight * height <= availableHeight && stepsByDepth * depth <= availableDepth)
        {
          resultLayout.IsVisible = true;

          stairsCountLabel.Text = "Ilość schodów: " + stepsByHeight;
          heightOfEachStairLabel.Text = "Wysokość każdego stopnia: " + height;
          depthOfEachStairLabel.Text = "Głębokość każdego stopnia: " + depth;
        }
      }
    }
  }
```
