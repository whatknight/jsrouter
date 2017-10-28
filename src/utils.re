let hasLeadingSlash = (path) => String.index(path, '/') == 0;
let hasTrailingSlash = (path) => String.rindex(path, '/') == String.length(path) - 1;
let ensureLeadingSlash = (path) => hasLeadingSlash(path) ? path : "/" ++ path;
let ensureTrailingSlash = (path) => hasTrailingSlash(path) ? path : path ++ "/";

let pathFromHash = (url) => {
  switch(Str.split("#", url)) {
  	| [_, path] => path
    | _ => "/"
  } |> ensureTrailingSlash |> ensureLeadingSlash
};

let noop = () => ();

let trimQueryParams = (path) => {
  switch(Str.split("?", path)) {
    | [path, _] => path
    | [path] => path
  }
};

let sanitizePaths = (paths) => {
  paths
  |> Js.Obj.keys
  |> Js.Array.reduce(
    (sanitized, key) => {
      sanitized.[key] = trimQueryParams paths.[key];
      sanitized
    },
    Js.Obj.empty())
};

/* type handler 'args = Js.t {. */
/*     f: Function, */
/*     args: 'args */
/* } as 'args; */
/* let callHandlers (handlers: array Handler) => { */
/*     handlers |> Js.Array.forEach (fun handler args => handler args); */
/* }; */
/*
 export function callHandlers(handlers) {
   handlers.forEach(({handler, args}) => {
     if (typeof handler === 'function') {
       handler(args);
     }
   });
 }

 export function getFlattenedHandlerArgs(handlers, startingArgs) {
   if (!handlers) { return startingArgs; }
   const args = handlers[0].args;
   const flattenedParams = handlers
     .reduce((mergedParams, {args: {params}}) => ({...mergedParams, ...params}), {});
   return {...args, params: flattenedParams};
 }
  */
