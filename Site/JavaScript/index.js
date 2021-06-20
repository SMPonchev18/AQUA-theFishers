function ResponsiveNavBar() 
{
    var nav = document.getElementById("navigationBar");
    if (nav.className === "navigationBarTop") 
    {
      nav.className += "responsive";
    } 
    else 
    {
      nav.className = "navigationBarTop";
    }
  }