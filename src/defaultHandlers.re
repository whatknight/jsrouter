type router = {. navigate: string => unit};

[@bs.val] external navigate : string => unit = "this.navigate";

let defaultUnrecognizedRouteHandler = (_, _) => navigate("/");

let defaultNavigateState = () => Js.Obj.empty();
