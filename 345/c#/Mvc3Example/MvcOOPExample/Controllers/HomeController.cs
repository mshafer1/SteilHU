using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace MvcOOPExample.Controllers
{
    public class HomeController : Controller
    {
        //
        // GET: /Home/

        public ActionResult Index()
        {
            Models.ExampleModel myModel = new Models.ExampleModel();
            return View(myModel);
        }

        public string Add(int x, int y)
        {
            return (x + y).ToString();
        }

        public ActionResult LoadExamplePartial()
        {
            return PartialView("_ExamplePartialView");
        }

        public ActionResult LoadExamplePartial2()
        {
            return PartialView("_ExamplePartialView2");
        }
    }
}
