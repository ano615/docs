module Styles = {
  open Css;

  let fadeIn = keyframes([(0, [opacity(0.)]), (100, [opacity(1.)])]);

  let main =
    style([
      opacity(0.),
      animationName(fadeIn),
      animationDuration(1000),
      animationDelay(200),
      animationFillMode(`forwards),
    ]);
};

let siteDescription = "Mina is the first cryptocurrency with a succinct blockchain. Our lightweight blockchain means anyone can use Mina directly from any device, in less data than a few tweets.";

[@react.component]
let make =
    (
      ~title,
      ~description=siteDescription,
      ~image="/static/img/favicon/favicon-96x96.png",
      ~route=?,
      ~children,
      ~darkTheme=false,
      ~showFooter=true,
      ~announcementCopy="Community Leaderboard Challenges are live!",
      ~announcementCTACopy="Take part now",
      ~announcementFormUrl=Constants.communityChallenges,
    ) => {
  let router = Next.Router.useRouter();
  let route = Option.value(route, ~default=router.route);

  <div className=Styles.main>
    <Next.Head>
      <title> {React.string(title)} </title>
      <meta property="og:title" content=title />
      <meta property="og:image" content=image />
      <meta property="og:type" content="website" />
      <meta property="og:description" content=description />
      <meta name="description" content=description />
      <meta property="og:url" content={Constants.minaProtocolUrl ++ route} />
      <link rel="canonical" href={Constants.minaProtocolUrl ++ route} />
      <link
        rel="icon"
        type_="image/png"
        href="/static/img/favicon/favicon-96x96.png"
        sizes="96x96"
      />
      <link
        rel="icon"
        type_="image/png"
        href="/static/img/favicon/favicon-32x32.png"
        sizes="32x32"
      />
      <link
        rel="icon"
        type_="image/png"
        href="/static/img/favicon/favicon-16x16.png"
        sizes="16x16"
      />
      <link href="/static/css/monument-grotesk.css" rel="stylesheet" />
      <link
        href="https://cdn.jsdelivr.net/npm/@ibm/plex@4.0.2/css/ibm-plex.min.css"
        rel="stylesheet"
      />
      <link href="https://use.typekit.net/mta7mwm.css" rel="stylesheet" />
      <style>
        {React.string("img:-moz-loading { visibility: hidden; }")}
      </style>
    </Next.Head>
    <Nav dark=darkTheme />
    <main> children </main>
    <CookieWarning />
    {showFooter ? <Footer /> : React.null}
  </div>;
};
