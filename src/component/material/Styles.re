type theme = {direction: string};

[@bs.module "@material-ui/core/styles"]
external makeStyle: (theme => unit) => 'b = "makeStyles";

[@bs.module "@material-ui/core/styles"]
external createStyles: 'a => 'b = "createStyles";
